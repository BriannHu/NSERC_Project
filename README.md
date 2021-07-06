# NoSQL Systems Design for Real-Time Data Analytics

This research project is generously supported by the [NSERC USRA](https://www.nserc-crsng.gc.ca/students-etudiants/ug-pc/usra-brpc_eng.asp), and supervised by [Dr. Oana Balmau](https://sites.google.com/view/oanabalmau). It is built upon existing work on [RocksDB](https://github.com/facebook/rocksdb) developed by Facebook.

## Motivation

In our modern era of technology, the goal of most (if not all) online platforms is to provide a customized experience to their users, by suggesting relevant items to adjust to their preferences. These recommendation systems ingest enormous amounts of information at a very high rate, and require a datastore that can simultaneously provide:

1. **High write throughput** to ingest the incoming user events.
2. **High read throughput** and **low read latency** to efficiently merge new information with the old data.
3. **Persistent storage**, since the amount of incoming data is large and is growing continuously.

It is achieving all three objectives simultaneously that is a challenge.

## Project Description

To address the challenge of designing an optimal recommendation system that satisfies the three requirements (high write throughput, high read throughput, persistent storage), this project will build upon Facebook's existing [RocksDB](https://github.com/facebook/rocksdb), which uses [log-structured merge trees](https://en.wikipedia.org/wiki/Log-structured_merge-tree). LSM trees are a popular data structure for write-optimized, persistent NoSQL datastores, but are not optimized for reads and provide little support for complex data structures like those in recommendation systems.

This project aims to augment the LSM tree that RocksDB uses, to support real-time recommendations on fresh data, and meet the three requirements of an effective modern recommendation system.

### Phase 1 - Implementing and Running a Representative Benchmark

To simulate a recommendation system for a social media platform, there are four "maps" (distinguished using different column families in RocksDB), which represent the different key-value pairs that store the data generated during a benchmark:

| Map                            | Key                    | Value\*                                                                    |
| ------------------------------ | ---------------------- | -------------------------------------------------------------------------- |
| 1) Picture Annotations         | ImageID                | Set[Annotation]                                                            |
| 2) Picture User Time Series    | UserID                 | Map{ImageID &#8594; Map{ActionID &#8594; (List[TimeStamp], Counter)}}      |
| 3) User Annotation Time Series | UserID                 | Map{AnnotationID &#8594; Map{ActionID &#8594; (List[TimeStamp], Counter)}} |
| 4) User Annotation Scores      | (UserID, AnnotationID) | Map{ActionID &#8594; Score}                                                |

\*In Phase 1, these maps are represented using RocksDB's [Slice](https://github.com/facebook/rocksdb/wiki/Basic-Operations#slice) structure.

The data of interest collected from the benchmark is:

- Average throughput of using all maps
- Average read/write latency of all maps
- 50th and 99th percentile read/write latency of all maps

An example figure generated using the benchmark is the following: <br>
![Map2 99th Percentile Figure](https://github.com/BriannHu/NSERC_Project/blob/master/figures/Map2_Read_2hr_99th_Percentile.png)
