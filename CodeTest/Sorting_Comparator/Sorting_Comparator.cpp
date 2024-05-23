#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player 
{
	int score;
	string name;
};

class Checker {
public:
	// complete this method
	static int comparator(Player a, Player b) 
	{
		// score is Ascending
		if (a.score > b.score)
		{
			return 1;
		}
		else if (b.score > a.score)
		{
			return -1;
		}
		else
		{
			// same score
			// compare name
			// name is descending order
			int value = a.name.compare(b.name);
			if (value > 0)
			{
				// a string > b.string
				// ex) char k > char c
				return -1;
			}
			else if (value < 0)
			{
				// a string < b.string
				// ex) char c < char d
				return 1;
			}
			else
			{
				// value == 0
				// same score same string
				return 0;
			}
			return 0;
		}
	}
};

bool compare(Player a, Player b) 
{
	if (Checker::comparator(a, b) == -1)
		return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<Player> players;
	string name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> name >> score;
		Player player;
		player.name = name, player.score = score;
		players.push_back(player);
	}
	sort(players.begin(), players.end(), compare);
	for (int i = 0; i < players.size(); i++) {
		cout << players[i].name << " " << players[i].score << endl;
	}
	return 0;
}