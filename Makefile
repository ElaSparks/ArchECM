 .PHONY: all clean run format
 rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
 
all: format
	cmake -Bbuild -H. && cd build && make

format:
			clang-format -i $(call rwildcard,.,*.cpp *.h)
	
clean:
	cd build && ls | grep -v '.gitkeep' | xargs rm -rf 
	cd bin && ls | grep -v '.gitkeep' | xargs rm -rf 
	
run:
	cd bin && ./ArchECM
