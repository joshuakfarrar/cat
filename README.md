### Benchmarks

###### Time to beat:

```sh
$ time cat ~/test.txt &>/dev/null

real    0m1.032s
user    0m0.000s
sys 0m0.312s
```

###### My times

v0.1.0

> **Reads from fp char by char and fprintf's to stdout**

```sh
$ time ./cat ~/test.txt &>/dev/null

real    0m28.657s
user    0m26.120s
sys 0m2.364s
```

v0.2.0

> **Creates a buffer of length of file size, copies in file, and prints**

```sh
$ time ./cat ~/test.txt &>/dev/null

real    0m1.267s
user    0m0.156s
sys 0m0.780s
```
