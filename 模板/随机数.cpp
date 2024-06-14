mt19937 mt(time(0));
uniform_int_distribution<int> dist(1,100);

int ran()
{
    return dist(mt);
}