#!/bin/bash

for i in {0..200}
do
  echo "cp $1_results/$2/$1_$i/unweighted_events.lhe /<path>/$3/unweighted_events_$i.lhe"
  cp $1_results/$2/$1_$i/unweighted_events.lhe /<path>/$3/unweighted_events_$i.lhe
done
