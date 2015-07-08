### Benchmarks

> These stats are kind of ridiculous and unreliable. This is an unscientific project.

###### Time to beat:

```sh
$ time cat ~/test.txt &>/dev/null

real    0m0.224s
user    0m0.000s
sys 0m0.220s
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

v0.3.0 (getting better!)

> **Stats the file for a rough blocksize to use for the buffer then reads in chunks**

```sh
$ time ./cat ~/test.txt 1>/dev/null

real    0m0.370s
user    0m0.068s
sys 0m0.300s
```
