#!/bin/sh

sudo docker build -t tensile:rocm-2.9 -f dockerfile-build-ubuntu-rock .
sudo docker run -it --name=ws_rocm-3.0 --network=host --device=/dev/kfd --device=/dev/dri --group-add video --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -v /home/alex/:/mnt/ tensile:rocm-2.9 bash
