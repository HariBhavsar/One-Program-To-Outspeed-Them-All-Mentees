CC=g++
CFLAGS=-Wall

R: Coins.cpp
	$(CC) $(CFLAGS) Coins.cpp -o Coins_R
	./Coins_R 1

M: Coins.cpp
	$(CC) $(CFLAGS) Coins.cpp -o Coins_M
	./Coins_M 2

Joint_Coins: Coins.cpp
	$(CC) $(CFLAGS) Coins.cpp -o Coins
	./Coins 3 

Test_Coins: Coins.cpp
	$(CC) $(CFLAGS) Coins.cpp -o Coins
	i=1; \
	while [ $$i -le 8 ]; do \
		echo $$i; \
		timeout 5 ./Coins 3 < tests_coins/$$i.in; \
		i=$$((i + 1)); \
	done;

Test_Subset: Subset_Sum.cpp
	$(CC) $(CFLAGS) Subset_Sum.cpp -o Subset_Sum
	i=1; \
	while [ $$i -le 8 ]; do \
		echo $$i; \
		timeout 5 ./Subset_Sum < tests_subsets/$$i.in; \
		i=$$((i + 1)); \
	done;
clean:
	rm Coins Coins_M Coins_R Subset_Sum
