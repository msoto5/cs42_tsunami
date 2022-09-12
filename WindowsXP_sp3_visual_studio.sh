#!/bin/bash 

#----Windows XP machine ready for developing----# 

mkdir tsunami
cd tsunami

set -e

vagrant init dvgamerr/win-xp-sp3
vagrant up --provider=virtualbox