# A variant cuckoo filter with various in-bucket eviction policies

## Prerequisites

* python ( under 3.7 )
* pandas, numpy, seaborn & matplotlib ( for drawing figures )
* cmake

## Build up

```
    cmake . -D{eviction_policies} && make clean && make all
```

Replace the {eviction_policies} with 

Built-in eviction policies include:
* RR: For each bucket, victim entries are selected in round-roubin.
* RANDOM: Randomly selecting the entry from the bucket to replace.
* AWARE: Similar with RANDOM, but pass the index of the most recent evicted entry. 
* FIRST: Always evicting the first entry. 

## Run benchmarks

```
    python test.py
```

This python script builds and tests cuckoo filters configured with four aforementioned eviction policies. We use Mersenne Twister to generate inserted items. Results are stored in *result/ploted_result.csv*, which could be simply parsed by `pandas.read_csv()`. 

## Plot figures

We build a Jupyter Notebook script *plot.ipynb* to parse the result file and plots visualize fpr, load factors, overheads and average relocation steps.  
