#!/bin/bash

wget https://en.wikipedia.org/wiki/Volvo_Cars

sed -i 's/[Vv][Oo][Ll][Vv][Oo]/The Best Company Ever/g' Volvo_Cars
mv Volvo_Cars Volvo_Cars.html