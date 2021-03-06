build:
	@g++ -w -std=c++14 -Wfatal-errors -static-libstdc++ \
	-L lib \
	-I include \
	./src/*.cpp \
	-o ./lib/bin/game.exe \
	-llua53 \
	-lmingw32 \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer \
	&& powershell write-host -fore Green Compile success

clean:
	@del game.exe

run:
	@powershell write-host -fore Green Game is running && "./lib/bin/game.exe"
