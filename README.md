# ASOPEB

##FP06

##FP07 - Mecanismos de sincronizacao - mutexes and shared memory

Command to compile

gcc file.c -o name_file_executavel_teste1 -lrt -lpthread -Wall

IDES
#netbeans
#eclipse
#intelij
#clion
#devhelp



Ram Memory
---------------------------------------------

$ sudo dmidecode -t memory

$ sudo dmidecode -t 16

$ sudo lshw -class memory
  #readible human-friendly

$  sudo dmidecode -t memory | grep -i size




tar.gz files
----------------------------------------------

$ tar -xzf archive.tar.gz

$ cd archive-name

$ ./configure

$ make

$ sudo make install


Check sum 256
-------------------------------------------

$ sha256sum <file>

Remove Any Apllications
--------------------------------------------

sudo apt-get purge <package-name>

NVIDA - commands
------------------------------------------

Commands history for NVida and Intel

$ sudo apt-get install bumblebee bumblebee-nvidia primus linux-headers-generic

$ lspci -v

$ sudo lspci -v

$ glxinfo

glxinfo -v

$   glxheads

$   optirun glxinfo

$   optirun modzilla

$   primusrun glxspheres.

$   primusrun glxspheres

$   sudo apt install virtualgl

$   cd ..

$   ls

$   cd etc/

$   ls -lai

$   cat environment 

$   nano environment 

$   sudo nano environment 

$   nano /etc/bumblebee/bumblebee.conf 

$   sudo nano /etc/bumblebee/bumblebee.conf 

Eclipse 
-------------------------------------------

https://www.eclipse.org/downloads/eclipse-packages/?show_instructions=TRUE



Sensors
------------------------------------------

$ sudo apt install mesa-utils

$ sensors

Youtube-dl
------------------------------------------
$ sudo wget https://yt-dl.org/downloads/latest/youtube-dl -O /usr/local/bin/youtube-dl

$ sudo chmod a+rx /usr/local/bin/youtube-dl

$ sudo apt-get install redshift redshift-gtk

Codecs and VLC
--------------------------------------------

$ sudo add-apt-repository ppa:videolan/master-daily

$ sudo apt install libavcodec-extra #Codecs 

$ sudo apt update

$ apt show vlc

Opendk -OpenSource- Java
--------------------------------------------

$ sudo apt install openjdk-11-jdk

$ sudo add-apt-repository ppa:webupd8team/java

$ sudo apt update

jDownloader
--------------------------------------------

http://jdownloader.org/download/index

IoT : Gitkraken
-------------------------------------------
Check snapcraft.io
Check man snap
$ snap find gitkraken

LaTex - TexMaker
-------------------------------------------
SoftwareCenter

Git
-------------------------------------------
Instructions file
$ sudo apt install git

Apt vs Apt-get vs dpkg
-------------------------------------------
» apt --comand line interface -- provides a high-level commandline interface for the package management system. It is intended as an end user interface
and enables some options better suited for interactive usage by default compared to more specialized APT tools like apt-get(8) and apt-cache(8).
»Much like apt itself, its manpage is intended as an end user interface and as such only mentions the most used commands and
options partly to not duplicate information in multiple places and partly to avoid overwhelming readers with a cornucopia of options and details.
»»apt-get -- package handling utility -- is the command-line tool for handling packages, and may be considered the user's "back-end" to other tools using the APT library. Several "front-end" interfaces exist, such as aptitude(8), synaptic(8) and wajig(1).

All features of apt(8) are available in dedicated APT tools like apt-get(8) and apt-cache(8) as well.  apt(8) just changes
the default value of some options (see apt.conf(5) and specifically the Binary scope). So you should prefer using these commands (potentially with some additional options enabled) in your scripts as they keep backward compatibility as much as possible.

»dpkg - package manager for Debian :» dpkg  is  a tool to install, build, remove and manage Debian packages. The primary and more user-friendly front-end for dpkg is aptitude(1). dpkg itself is controlled entirely via command line parameters, which consist of exactly one action and zero or more options. The action-parameter tells dpkg what to do and options control the behavior of the action in some way.
