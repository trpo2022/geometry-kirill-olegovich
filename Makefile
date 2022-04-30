app_name = geometry
lib_name = libgeometry

cflags = -Wall -Werror -I src -MP -MMD
# cflags2 = -Wall -Werror
myflag = -lm

app_path = bin/$(app_name)
lib_path = obj/src/$(lib_name)/$(lib_name).a

app_sources = $(shell find src/$(app_name) -name '*.cpp')
app_objects = $(app_sources:src/%.cpp=obj/src/%.o)

lib_sources = $(shell find src/$(lib_name) -name '*.cpp')
lib_objects = $(lib_sources:src/%.cpp=obj/src/%.o)

# deps = $(app_objects:.o=.d) $(lib_objects:.o=.d)

# test_name = test
# test_path = bin/$(test_name)

# test_sources = $(shell find test/ -name '*.cpp')
# test_objects = $(test_sources:test/%.cpp=obj/test/%.o)

# test_deps = $(test_objects:.o=.d) $(lib_objects:.o=.d)


.PHONY: all
all: $(app_path)

# -include $(deps)

$(app_path): $(app_objects) $(lib_path)
	g++ $(cflags) -DTEST $^ $(myflag) -o $@

$(lib_path): $(lib_objects)
	ar rcs $@ $^

obj/%.o: %.cpp
	g++ -c $(cflags) $< $(myflag) -o $@




.PHONY: test
test: $(test_path)

# -include $(test_deps)

$(test_path): $(test_objects) $(lib_path)
	g++ $(cflags) -I thirdparty -I src $^ $(myflag) -o $@

# obj/%.o: %.cpp
# 	g++ -c $(cflags) -I thirdparty -I src $< $(myflag) -o $@




.PHONY: clean
clean:
	$(RM) $(app_path) $(test_path) $(lib_path)
	find obj/ -name '*.o' -exec $(RM) '{}' \;
	find obj/ -name '*.i' -exec $(RM) '{}' \;
	find obj/ -name '*.d' -exec $(RM) '{}' \;


