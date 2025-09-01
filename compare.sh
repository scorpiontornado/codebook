./gen > random.in; while diff <(./soln < random.in) <(./brute_force < random.in); do echo "all good"; ./gen > random.in; done
