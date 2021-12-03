import os
import re
from subprocess import Popen, PIPE
import pandas as pd

executable = "./bin/cuckoo_filter"

workers = {}
for i in range(10, 22):
    command = " ".join([executable, str(2**i)])
    workers[i] = Popen(command, stdout=PIPE, stderr=PIPE, shell=True, preexec_fn=os.setpgrp)

df = pd.DataFrame(columns=["capacity", "alpha", "fpr"])
for capacity, worker in workers.items():
    out, err = worker.communicate()
    pattern = re.compile(r"([1-9]\d*\.\d*|0\.\d*[1-9]\d*|1$|0$)", re.MULTILINE)
    lr, fpr = map(lambda x: float(x), pattern.findall(out.decode('utf-8')))
    df = df.append(dict(zip(df.columns, [capacity, lr, fpr])), ignore_index=True)

df.to_csv("result/cuckoo-4.csv")
print(df)
