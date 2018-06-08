SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))

bin/program : $(OBJECTS)
	@mkdir -p ./bin
	@g++  $^ -o $@ 

obj/%.o : src/%.cpp
	@mkdir -p ./obj
	@g++ -c $< -I./src -o $@

deps/%.dep : src/%.cpp
	@mkdir -p ./deps
	@g++ -MM $< -MT "$@ $(patsubst deps/%.dep, obj/%.o, $@)" -o $@ -I./src

-include $(DEPENDS)

clean :
	@echo "cleaning..."
	@rm -rf obj bin deps
	@rm -rf docs/doxygen
	@rm -f  test/*.o test/run
	

.PHONY : test
test : 
	@g++ -c ./src/smart_array.cpp -I./src -o test/smart_array.o
	@g++ -c ./test/test.cpp -I./src -o test/test.o
	@g++ ./test/smart_array.o ./test/test.o -o ./test/run

.PHONY : test_run
test_run : 
	 @cd ./test; ./run@> test/output.txt
       	
doxygen :
	@mkdir -p ./docs/doxygen
	@doxygen ./Doxyfile

html : doxygen
	@firefox ./docs/doxygen/html/index.html

run : bin/program
	@./bin/program
