Elle devra également être à jour ainsi que l’ensemble des packages installés pour
répondre aux demandes de ce sujet.   
`apt-get update`   
`apt-get upgrade`   
`sudo apt-get build-dep build-essential`

Packages necessaire (important):   
`apt-get install net-tools` *Permet d'utiliser ifconfig*   
`apt-get install iptables-persistent` *Permet d'avoir des regles de parefeu persistante*   
`apt-get install sudo` *Permet d'avoir la commande sudo*

Design termianl (optionnel):   
`apt-get install zsh`   
`apt-get install git`   
`$ sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"`   
Theme: `https://raw.githubusercontent.com/channprj/dotfiles-macOS/master/custom-zsh-theme/dpoggi-timestamp.zsh-theme`

Nous ne voulons pas que vous utilisiez le service DHCP de votre machine.   
A vous donc de la configurer afin qu’elle ait une IP fixe et un Netmask en /30.

Dans VirtualBox, Preferences, Network, creer un nouveau NAT Networks mettre:   
`10.0.2.0/30`

Ensuite dans les Settings de la VM, Network selectionner NET Network dans *Attached to:*

Ouvrir:   
`nano /etc/network/interfaces`

Modifier la partie *Primary network interface*   
```
auto enp0s3
iface enp0s3 inet static
      address     10.0.2.0
      netmask     255.255.255.252
      gateway     10.0.2.1
```

On redemarre le service: `service networking restart` et on reconfigure l'interface reseau: `ifdown enp0s3` puis `ifup enp0s3`

Reboot la VM: `shutdown -r now`

-----------

Vous devez changer le port par defaut du service SSH par celui de votre choix.   
`nano /etc/ssh/sshd_config`   
Editer la ligne: `#Port 22` par `Port 25665`

L’accès SSH DOIT se faire avec des publickeys.   
On genere une clé et certificat: `ssh-keygen`

L’utilisateur root ne doit pas pouvoir se connecter en SSH.   
`nano /etc/ssh/sshd_config`   
Editer la ligne `#PermitRootLogin ...` par `PermitRootLogin no`

Vous devez mettre en place des règles de pare-feu (firewall) sur le serveur avec uniquement les services utilisés accessible en dehors de la VM.   
La commande pour afficher le firewall:   
`iptables -L -v -n --lines-numbers`   

Installer *nmap* pour detecter les ports ouverts.   
`apt-get install nmap`   
Checker tous les ports avec:   
`nmap -p 0-65535 127.0.0.1`   

Une fois les ports ouverts detecter, on autorise les ports nécessaire, dans notre cas on autorise le port du service SSH.   
`iptables -A INPUT -i enp0s3 -p tcp --dport 21 -j ACCEPT`   
On autoriser la commande ping:   
`iptables -A INPUT -p icmp -j ACCEPT`   
On autorise egalement toute les connexions déjà établies:   
`iptables -A INPUT -i enp0s3 -m state --state ESTABLISHED,RELATED -j ACCEPT`   
Et enfin on bloque tout le reste:   
`iptables -A INPUT -i enp0s3 -j DROP`   

**Trouver une solution pour demarrer le script des commandes Firewall.**   


