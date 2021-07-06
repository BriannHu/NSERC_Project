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

### Phase 1 - Implementing and Running Representative Benchmark

To simulate a recommendation system for a social media platform, the set of all possible actions is defined with the following:
| ActionType | Default %\* |
|------------|----------:|
| VIEW | 60% |
| LIKE | 20% |
| SHARE\*\* | 15% |
| ADD | 5% |

\* The chance of each action occuring is arbitrary and can be modified in the benchmark. <br>
\*\* Upon each SHARE action, additional iterations of the action loop are performed. This simulates how after a post is shared, there will be additional actions that are associated with it.
