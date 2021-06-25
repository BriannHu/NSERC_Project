#!/bin/bash

filename=`date "+%Y-%m-%d_%T"`
duration=21600 # seconds

echo "current filename: ${filename}"
echo "curration duration: ${duration} seconds"

./db_bench --benchmarks=brianbenchmark2 --statistics=1 --histogram=1 --threads=1 --key_si    ze=8 --value_size=1000 --open_files=500000 --verify_checksum=1 --compression_type=none --    stats_interval=1000000 --write_buffer_size=134217728 --max_write_buffer_number=2 --stats_    interval_seconds=2 --use_existing_db=0 --duration=${duration} --num=1000000 --popular_use    rs=0.01 --num_column_families=5 > LOG_FILES/BENCHMARK_OUTPUTS/STDOUT/${filename}.txt 2> L    OG_FILES/BENCHMARK_OUTPUTS/STDERR/${filename}.txt

echo "Benchmark completed!"
