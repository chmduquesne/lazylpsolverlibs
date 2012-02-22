# This part of the project requires non free headers to build. However
# only the headers are needed. The actual solvers are required to run it
# succesfully.

CC=gcc

CPLEX_INCLUDE_PATH=./include
XPRESS_INCLUDE_PATH=./include
GUROBI_INCLUDE_PATH=./include
GLPK_INCLUDE_PATH=./include

all: test_lazylpsolverlibs

# For your convenience, an archive can be downloaded.
download:
	@wget -c https://lazylpsolverlibs.googlecode.com/files/solver_headers.tar.gz
	@tar xzf solver_headers.tar.gz
	@rm solver_headers.tar.gz

../lib:
	make -c ..

test_lazycplex.o: test_lazycplex.c
	$(CC) -Wall -I $(CPLEX_INCLUDE_PATH) -I ../cplex -I ../common -c $<

test_lazyxprs.o: test_lazyxprs.c
	$(CC) -Wall -I $(XPRESS_INCLUDE_PATH) -I ../xprs -I ../common -c $<

test_lazygurobi.o: test_lazygurobi.c
	$(CC) -Wall -I $(GUROBI_INCLUDE_PATH) -I ../gurobi -I ../common -c $<

test_lazyglpk.o: test_lazyglpk.c
	$(CC) -Wall -I $(GLPK_INCLUDE_PATH) -I ../glpk -I ../common -c $<

test_lazylibs.o: test_lazylibs.c
	$(CC) -Wall -c $<

test_lazylpsolverlibs: ../lib test_lazycplex.o test_lazyxprs.o test_lazygurobi.o test_lazyglpk.o test_lazylibs.o
	$(CC) -Wall -L ../lib -lltdl -llazycplex -llazyxprs -llazygurobi -llazyglpk *.o -o test_lazylpsolverlibs

clean:
	rm -rf include
	rm -f *.o test_lazylpsolverlibs
