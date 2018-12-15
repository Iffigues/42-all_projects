basename $(find . -type f -name '*.sh' -print) | rev | cut -c 4- | rev
