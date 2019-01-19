# Simple project using catch2 and cmake

This example is a complete quick-start for cmake with catch2 integration. If you have catch2 installed, then just run:

```bash
cmake -Bbuild -H.
cmake --build build
cmake --build build --target test
```

## Installing catch2 cmake helpers

Just install catch2 from git source. This example works for sure with:

```bash
wget https://codeload.github.com/catchorg/Catch2/tar.gz/v2.5.0 -O v2.5.0.tar.gz
tar -xvf v2.5.0.tar.gz
cd Catch2-2.5.0
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build --target install
```



