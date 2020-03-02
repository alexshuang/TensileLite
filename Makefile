target = tl
OBJS = src/main.o src/gemmMfma.o
LIBS = -lff_gpu -lff_utils -lhip_hcc
ROCM_PATH=/opt/rocm
CFLAGS = -O2 -Iinc -I$(ROCM_PATH)/hip/include -I$(ROCM_PATH)/include -std=c++11
LDFLAGS = -Llib -L$(ROCM_PATH)/lib

$(target): $(OBJS)
	g++ $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	g++ $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJS) $(target)
