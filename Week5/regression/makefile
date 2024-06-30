CC=g++

regression: main.cpp
	$(CC) main.cpp regression.cpp ../matrix/matrix.cpp -o main
	python3 plotter.py
clean:
	rm main