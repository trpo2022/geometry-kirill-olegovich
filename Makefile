app_name = geometry
lib_name = libgeometry

cflags = -Wall -Wextra -Werror
cppflags = -I src -MP -MMD

app_path = bin/$(app_name)
lib_path = obj/src/$(lib_name)/$(lib_name).a

app_sources = $(shell find src/$(app_name) -name '*.c')
app_objects = $(app_sources:src/%.c=obj/%.o)

lib_sources = $(shell find src/$(lib_name) -name '*.c')
lib_objects = $(lib_sources:src/%.c=obj/%.o)

deps = $(app_objects:.o=.d) $(lib_objects:.o=.d)

all: $(app_path)

-include $(deps)

$(app_path): $(app_objects) $(lib_path)
	gcc $(cflags) $(cppflags) $^ -o $@

$(lib_path): $(lib_objects)
	ar rcs $@ $^

obj/%.o: %.c
	gcc -c $(cflags) $(cppflags) %< -o $@

clean:
	$(RM) $(app_path) $(lib_path)
	find $(obj_dir) -name '*.o' -exec $(RM) '{}' \;
	find $(obj_dir) -name '*.d' -exec $(RM) '{}' \;
