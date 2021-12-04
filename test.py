import os
import re
from subprocess import Popen, PIPE
import pandas as pd

executable = "./bin/cuckoo_filter"

workers = {}
for i in range(10, 22):
    command = " ".join([executable, str(2**i)])
    workers[i] = Popen(command, stdout=PIPE, stderr=PIPE, shell=True, preexec_fn=os.setpgrp)

df = pd.DataFrame(columns=["capacity", "bucket_size", "alpha", "fpr"])
for capacity, worker in workers.items():
    out, err = worker.communicate()
    for line in out.decode("utf-8").split("\n"):
        if line:
            data = list(map(float, line.split(" ")))
            df = df.append(dict(zip(df.columns, data)), ignore_index=True)

df["capacity"] = df["capacity"].astype(int)
df["bucket_size"] = df["bucket_size"].astype(int)
df.to_csv("result/cuckoo.csv")
print(df)
