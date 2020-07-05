# writer_reader_program
 Project for the Operating Systems course

The Operating Systems project is organized in 5 linked parts.
Overall the project consists of developing a program called Writer-Reader that, as the name implies, performs writing and reading operations on files.
The 5 parts that make up the project address the following topics:

- Part 1: Sequential version of the WRITER and READER programs.

- Part 2_ Parallel version of the WRITER program; a parent process creates several child processes and these are the ones that, in competition, execute the writing operations on the files, leaving the parent process to measure and print the total time of the program execution.

- Part 3: At this stage, it was necessary to synchronize access to files by the WRITER programs; in effect, it was intended to ensure that if a process is writing to a given file, no other process can be writing to that file. Several READER processes should be able to read the same files concurrently.

- Part 4: In this phase, it was intended that the READER processes are able to verify the coherence of 3 files concurrently. To this end, two versions were developed:
i) one in which there is a parent program that creates 3 child processes (each of which will make a check), and ii) another in which 3 threads will be created to perform the same task.

- Part 5: In this last phase, it was intended to develop new versions of the READER (with parallelism) with more complex synchronization between the various threads in the access to a shared buffer that contains the names of the files read from the keyboard (of the type writer-readers) and a monitor process that manages the threads mentioned before.
