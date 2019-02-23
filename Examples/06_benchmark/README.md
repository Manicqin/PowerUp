# 06_Benchmark

Benchmark project for the addons included in the PowerUp examples.

The machine running the benchmarks is personal laptop:

    Kubuntu 17.10 (64)

    I5-7200U CPU @ 2.5Ghz

    8GB Ram 


1. benchmark.js is a race between the 3 types of native modules V8, Nan And NAPI 
that are included as part the repository.
 

  • reverse_string...

    ✔  V8    4,604,300.02  ops/sec  ±4.26%  (86 runs)  -16.54%
    ✔  Nan   5,516,652.59  ops/sec  ±0.81%  (89 runs)  fastest
    ✔  Napi  4,227,156.53  ops/sec  ±0.87%  (89 runs)  -23.37%

    ➔ Fastest is Nan

  • distance_between...

    ✔  V8    1,412,249.42  ops/sec  ±0.98%  (94 runs)  fastest
    ✔  Nan   1,139,382.72  ops/sec  ±0.73%  (90 runs)  -19.32%
    ✔  Napi    719,187.30  ops/sec  ±0.72%  (92 runs)  -49.08%

    ➔ Fastest is V8

  • sum int...

    ✔  V8    12,066,864.44  ops/sec  ±0.74%  (89 runs)  fastest
    ✔  Nan   10,229,438.36  ops/sec  ±0.94%  (89 runs)  -15.23%
    ✔  Napi   6,317,483.38  ops/sec  ±0.80%  (92 runs)  -47.65%

    ➔ Fastest is V8

  • sum int array...

    ✔  V8    3,334,923.19  ops/sec  ±0.72%  (94 runs)  fastest
    ✔  Nan   3,013,510.86  ops/sec  ±0.82%  (93 runs)   -9.64%
    ✔  Napi  1,799,184.88  ops/sec  ±0.81%  (91 runs)  -46.05%

    ➔ Fastest is V8

  • unique sort array...

    ✔  V8    980,727.62  ops/sec  ±1.48%  (92 runs)  fastest
    ✔  Nan   958,095.82  ops/sec  ±0.74%  (93 runs)   -2.31%
    ✔  Napi  627,765.18  ops/sec  ±0.69%  (92 runs)  -35.99%

    ➔ Fastest is V8

2. benchmark2.js is a race between 2 top "count words occurrences" modules from npm and the NAPI module: 

  • count words 10 lorem Ipsum words...

    ✔  03_NAPI                                               20,027.12  ops/sec  ±1.49%  (89 runs)  fastest
    ✔  https://www.npmjs.com/package/count-words-occurrence   2,167.02  ops/sec  ±1.56%  (89 runs)  -89.18%
    ✔  https://www.npmjs.com/package/count-words              8,189.77  ops/sec  ±2.50%  (87 runs)  -59.11%

    ➔ Fastest is 03_NAPI

  • count words 100 lorem Ipsum words...

    ✔  03_NAPI                                               2,714.52  ops/sec  ±0.88%  (90 runs)  fastest
    ✔  https://www.npmjs.com/package/count-words-occurrence     67.31  ops/sec  ±0.88%  (68 runs)  -97.52%
    ✔  https://www.npmjs.com/package/count-words               905.52  ops/sec  ±1.12%  (92 runs)  -66.64%

    ➔ Fastest is 03_NAPI

  • count words 1000 lorem Ipsum words...

    ✔  03_NAPI                                               320.01  ops/sec  ±0.82%  (87 runs)  fastest
    ✔  https://www.npmjs.com/package/count-words-occurrence    4.39  ops/sec  ±3.62%  (15 runs)  -98.63%
    ✔  https://www.npmjs.com/package/count-words              82.59  ops/sec  ±2.48%  (70 runs)  -74.19%

    ➔ Fastest is 03_NAPI
    
3. warAndPeace is a race who will count the occurrences of words faster using the novel War And Peace

Sadly the module count-words-occurrence failed to finish ... 


    NAPI:           428.738ms
    
    count_words:    905.236ms