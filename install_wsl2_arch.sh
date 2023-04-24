#!/bin/bash

sudo pacman -S base-devel cmake wget curl git python python-pip exa ranger neovim
code .
./install_vscode_extensions.sh
cd ~
mkdir ./.build
cd ./.build
git clone https://aur.archlinux.org/yay-bin.git
cd ./yay-bin
makepkg -si

