#!/bin/bash
for f in ./*.bmp; do echo -n "$f "; convert "$f" "${f%bmp}png"; done 
mkdir png
mv ./*.png ./png
