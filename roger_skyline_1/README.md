# roger-skyline-1
Roger-Skyline-1. This subject follows Init where you have learn some of basics commands and first reflexes in system and network administration. This one will be a concrete exemple of the use of those commands and will let you start your own first web server.

OS: Debian 9.6.0 Netinst
- [x] **Une taille de disque de 8 Go**
- [x] **Avoir au moins une partition de 4.2 Go**
- [x] **Elle devra également être à jour**   
`apt-get update`   
`apt-get upgrade`
- [x] **Ensemble des packages installés**   
`sudo apt-get build-dep build-essential`
- [x] **Vous devez créer un utilisateur non root**   
`adduser Roger`
- [x] **Utilisez sudo pour pouvoir**   
`apt-get install sudo`
- [x] **Nous ne voulons pas que vous utilisiez le service DHCP de votre machine**   
`nano /etc/network/interface`   
Modifier *dhcp* par *static*
- [x] **Une IP fixe et un Netmask en /30**   
`nano /etc/network/interface`   
```
iface enp0s3 inet static
      address     10.0.2.0
      netmask     255.255.255.252 # <-- /30
      gateway     10.0.2.1
```
- [x] **Vous devez changer le port par defaut du service SSH par celui de votre choix**   
`nano /etc/ssh/sshd_config`   
Modifier `#Port 22` par `Port 25665`
- [x] **L’accès SSH DOIT se faire avec des publickeys**   
`nano /etc/ssh/sshd_config`   
Modifier `#PubkeyAuthentication yes` par `PubkeyAuthentication yes`
- [x] **L’utilisateur root ne doit pas pouvoir se connecter en SSH**  
Modifier `#PermitRootLogin prohibit-password` par `PermitRootLogin no`
- [x] **Vous devez mettre en place des règles de pare-feu uniquement les services utilisés accessible en dehors de la VM**   
Installer ce packet pour rentre les regles du firewall persistante   
`apt-get install iptables-persistent`   
```
# Reinitialise les regles
iptables -t filter -F
iptables -t filter -X
# Autorise les connexions deja etablies et localhost
iptables -A INPUT -m state --state RELATED,ESTABLISHED -j ACCEPT
iptables -t filter -A INPUT -i lo -j ACCEPT
# Bloque tout le trafic
iptables -t filter -P INPUT DROP 
# Autorise PING
iptables -t filter -A INPUT -p icmp -j ACCEPT 
# Autorise SSH et WEB
iptables -t filter -A INPUT -p tcp --dport 25665 -j ACCEPT
iptables -t filter -A INPUT -p tcp --dport 80 -j ACCEPT
iptables -I INPUT 1 -p tcp --dport 443 -j ACCEPT
```
`iptables-save > /etc/iptables/rules.v4`   
`iptables-save > /etc/iptables/rules.v6`
- [x] **Vous devez mettre en place une protection contre les DOS et contre les scans sur les ports ouverts**
```
iptables -t mangle -A PREROUTING -m conntrack --ctstate INVALID -j DROP
iptables -t mangle -A PREROUTING -p tcp ! --syn -m conntrack --ctstate NEW -j DROP 
iptables -t mangle -A PREROUTING -p tcp -m conntrack --ctstate NEW -m tcpmss ! --mss 536:65535 -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,SYN,RST,PSH,ACK,URG NONE -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,SYN FIN,SYN -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags SYN,RST SYN,RST -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,RST FIN,RST -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags FIN,ACK FIN -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ACK,URG URG -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ACK,FIN FIN -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ACK,PSH PSH -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL ALL -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL NONE -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL FIN,PSH,URG -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL SYN,FIN,PSH,URG -j DROP
iptables -t mangle -A PREROUTING -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG -j DROP
iptables -t mangle -A PREROUTING -s 224.0.0.0/3 -j DROP
iptables -t mangle -A PREROUTING -s 169.254.0.0/16 -j DROP
iptables -t mangle -A PREROUTING -s 172.16.0.0/12 -j DROP
iptables -t mangle -A PREROUTING -s 192.0.2.0/24 -j DROP
iptables -t mangle -A PREROUTING -s 192.168.0.0/16 -j DROP
iptables -t mangle -A PREROUTING -s 10.0.0.0/8 -j DROP
iptables -t mangle -A PREROUTING -s 0.0.0.0/8 -j DROP
iptables -t mangle -A PREROUTING -s 240.0.0.0/5 -j DROP
iptables -t mangle -A PREROUTING -s 127.0.0.0/8 ! -i lo -j DROP
iptables -t mangle -A PREROUTING -p icmp -j DROP
iptables -t mangle -A PREROUTING -f -j DROP
iptables -A INPUT -p tcp -m connlimit --connlimit-above 111 -j REJECT --reject-with tcp-reset
iptables -A INPUT -p tcp --tcp-flags RST RST -m limit --limit 2/s --limit-burst 2 -j ACCEPT
iptables -A INPUT -p tcp --tcp-flags RST RST -j DROP
iptables -A INPUT -p tcp -m conntrack --ctstate NEW -m limit --limit 60/s --limit-burst 20 -j ACCEPT
iptables -A INPUT -p tcp -m conntrack --ctstate NEW -j DROP
iptables -A INPUT -p tcp --dport ssh -m conntrack --ctstate NEW -m recent --set
iptables -A INPUT -p tcp --dport ssh -m conntrack --ctstate NEW -m recent --update --seconds 60 --hitcount 10 -j DROP
iptables -N port-scanning
iptables -A port-scanning -p tcp --tcp-flags SYN,ACK,FIN,RST RST -m limit --limit 1/s --limit-burst 2 -j RETURN
iptables -A port-scanning -j DROP
```
*Protection DDOS et Brutforce [Source](https://javapipe.com/blog/iptables-ddos-protection/)*
- [x] **Arretez les services dont vous n’avez pas besoin pour ce projet**   
Installation de l'OS Debian Netinst avec uniquement les services SSH et WEB
- [x] **Réalisez un script qui met à jour l’ensemble des sources de package**   
`cd /etc/cron.d`   
`echo "#!/bin/bash sudo apt-get update > /var/log/update_script.log && sudo apt-get upgrade >> /var/log/update_script.log" > update_script.sh`    
- [x] **Plannifiée pour ce script une fois par semaine à 4h00 du matin et à chaque reboot de la machine.**   
Utiliser `crontab -e` pour ouvrir le fichier qui permet d'ajouter une tache, mettre dedans:
```
0 4 * * 6 /etc/cron.d/update_script.sh   
@reboot /etc/cron.d/update_script.sh
```
- [ ] **Réalisez un script qui permet de surveiller les modifications du fichier /etc/crontab**   
*Voir inotify*

- [ ] **Envoie un mail à root si celui-ci a été modifié**   
`apt-get install sendmail`
`apt-get install ssmtpf`

- [ ] **Créez une tache plannifiée pour script tous les jours à minuit**
- [x] **Vous avez le choix entre Nginx et Apache**
- [ ] **Mettre en place du SSL auto-signé sur l’ensemble de vos services**
- [ ] **Une page de login**
- [ ] **Un site vitrine**
- [ ] **Un site qui nous vend du rêve**
- [ ] **Proposez une solution fonctionnelle d’automatisation de deploiement**
