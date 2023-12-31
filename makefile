# MAC ONLY (LINUX COMPATIBLE IF MODIFIED)

comp:
	g++ src/*.c++ demo/*.c++ -o build/HeatforgeAlpha.app/Contents/MacOS/heatforge -Wl,-rpath,@executable_path/../Frameworks -F/opt/homebrew/Cellar/sdl2/ -F/opt/homebrew/Cellar/sdl2_image/ -framework SDL2 -framework SDL2_image -Ofast -std=c++17 ; cp -R demo/Resources build/HeatforgeAlpha.app/Contents/ ; cp -R demo/Frameworks build/HeatforgeAlpha.app/Contents/ ; codesign --force --deep --sign - build/HeatforgeAlpha.app ; cd build/HeatforgeAlpha.app/Contents/MacOS/ ; ./heatforge ; cd ../../../../