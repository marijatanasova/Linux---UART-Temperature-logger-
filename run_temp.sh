#!/bin/bash 
echo "Starting temperature logger..."
./temperature
echo "Done. Check temperature.log for results."
cat temperature.log
