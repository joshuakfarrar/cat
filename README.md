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

v0.4.0 (pretty sure i broke physics)

> **Uses mmap to map file directly to memory and fwrites it to stdout**

```sh
$ time ./cat ~/test.txt &>/dev/null

real    0m0.001s
user    0m0.000s
sys 0m0.000s
```

Just to be sure on this version, because the numbers when piping to /dev/null don't make sense, these are the numbers when piping to a file:

```sh
$ time ./cat ~/test.txt 1>test.txt

real    0m4.533s
user    0m0.000s
sys 0m1.088s

$ time cat ~/test.txt 1>test.txt

real    0m4.738s
user    0m0.000s
sys 0m1.144s
```

Also...

```sh
$ time ./cat ~/test.txt | wc -l 1>/dev/null

real    0m1.287s
user    0m0.468s
sys 0m0.812s

time cat ~/test.txt | wc -l 1>/dev/null

real    0m1.432s
user    0m0.484s
sys 0m0.944s
```
