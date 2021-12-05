import os
from subprocess import Popen, PIPE
import pandas as pd


def test_benchmark(evict):
    # compile the project first
    os.system("cmake -DEVICT_STYLE={} . && make clean && make -j".format(evict))
    executable = "./bin/cuckoo_filter"

    # test different filter capacity in parallel
    workers = {}
    for i in range(10, 20):
        command = " ".join([executable, str(2**i)])
        workers[i] = Popen(command, stdout=PIPE, stderr=PIPE, shell=True, preexec_fn=os.setpgrp)

    # collect outputs
    df = pd.DataFrame(columns=["capacity", "bucket_size", "alpha", "fpr", "rehash"])
    for capacity, worker in workers.items():
        out, err = worker.communicate()
        for line in out.decode("utf-8").split("\n"):
            if line:
                data = list(map(float, line.split(" ")))
                df = df.append(dict(zip(df.columns, data)), ignore_index=True)

    df["capacity"] = df["capacity"].astype(int)
    df["bucket_size"] = df["bucket_size"].astype(int)
    df.to_csv("result/cuckoo-{}.csv".format(evict))
    return df


ploted_result = pd.DataFrame()
evict_types = ["RR", "FIRST", "RANDOM", "AWARE"]
for evict in evict_types:
    res = test_benchmark(evict)
    res["type"] = evict
    ploted_result = ploted_result.append(res, ignore_index=True)

print(ploted_result)
ploted_result.to_csv("result/ploted_result.csv")