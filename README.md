# cs42_tsunami
Proyect which consists of creating a C program that causes a simple buffer overflow in a Windows XP 32-bit environment. The buffer owerflow will be perform by strcpy function.

## Getting Started
A Windows XP virtual machine was used to perform the project. Another possible options is using a Docker container.

### Installing Windows XP Virtual Machine 
You can easily create a virtual machine with **vagrant** following the following steps:
1. [Install VirtualBox](https://www.virtualbox.org/wiki/Downloads) in your machine
2. [Install vagrant](https://www.vagrantup.com/downloads)
3. Run [WindowsXP_sp3_visual_studio.sh](WindowsXP_sp3_visual_studio.sh)
4. Open virtual machine with virtualbox

Once it is already installed, virtualbox is used to boot up and open it.

VirtualBox lets having shared clipboards and to drag files between host and guest machines. You can enable it in the top menú:
- **Shared Clipboard**: Devices > Shared Clipboard > Bidirectional
- **Drag and Drop**: Devices > Drag and Drop > Bidirectional

## Fast Usage
1. Compile tsunami.c and payload.c
2. Send them to guest machine to the same folder (this can be made by dragging them with virtualbox function)
3. Run payload:
'''bash
./payload
'''
