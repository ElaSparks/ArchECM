 .PHONY: all clean run
 
all: 
	cmake -Bbuild -H. && cd build && make
	
clean:
	cd build && ls | grep -v '.gitkeep' | xargs rm -rf 
	cd bin && ls | grep -v '.gitkeep' | xargs rm -rf 
	
run:
	cd bin && ./ArchECM
