#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

void dijkstra(const vector<vector<pair<int, int>>>& adj, const vector<string>& cityNames, int source, int destination) {
    int numCities = adj.size();
    vector<int> dist(numCities, INT_MAX);
    vector<int> prev(numCities, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (const auto& [v, weight] : adj[u]) {
            int distance = currentDist + weight;
            if (distance < dist[v]) {
                dist[v] = distance;
                prev[v] = u;
                pq.push({distance, v});
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "No shortest distance found" << endl;
        return;
    }

    cout << "Shortest distance from " << cityNames[source] << " to " << cityNames[destination] << " is " << dist[destination] << endl;
    cout << "Path: ";
    vector<int> path;
    for (int at = destination; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i) {
        cout << cityNames[path[i]];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    const int numCities = 20;
    vector<string> cityNames = {
        "Vizianagaram", "Myhome", "Hemanth", "Pedhatadivada", "Sathu", "Phoolbagh", "Ayekonneru",
        "Mahathi", "Bhargav", "Vara", "Dharampuri", "More", "PradeepNagar", "Dmart", "Bhavish",
        "NCS", "Railway", "BusStand", "SVN", "Mandi"
    };

    unordered_map<string, int> cityIndex;
    for (int i = 0; i < cityNames.size(); ++i) {
        cityIndex[cityNames[i]] = i;
    }

    vector<vector<pair<int, int>>> adj(numCities);
    adj[cityIndex["Vizianagaram"]] = { {cityIndex["Myhome"], 17}, {cityIndex["Pedhatadivada"], 3}, {cityIndex["Phoolbagh"], 6}, {cityIndex["Ayekonneru"], 1}, {cityIndex["Dharampuri"], 6}, {cityIndex["Mahathi"], 1}, {cityIndex["PradeepNagar"], 3} };
    adj[cityIndex["Myhome"]] = { {cityIndex["Hemanth"], 10}, {cityIndex["Pedhatadivada"], 14}, {cityIndex["Sathu"], 7} };
    adj[cityIndex["Hemanth"]] = { {cityIndex["Myhome"], 10}, {cityIndex["Pedhatadivada"], 4} };
    adj[cityIndex["Pedhatadivada"]] = { {cityIndex["Myhome"], 14}, {cityIndex["Vizianagaram"], 3} };
    adj[cityIndex["Sathu"]] = { {cityIndex["Myhome"], 7}, {cityIndex["Phoolbagh"], 7} };
    adj[cityIndex["Phoolbagh"]] = { {cityIndex["Sathu"], 7}, {cityIndex["Vizianagaram"], 6} };
    adj[cityIndex["Ayekonneru"]] = { {cityIndex["Vizianagaram"], 1} };
    adj[cityIndex["Mahathi"]] = { {cityIndex["Vizianagaram"], 1}, {cityIndex["Bhargav"], 1} };
    adj[cityIndex["Bhargav"]] = { {cityIndex["Mahathi"], 1}, {cityIndex["PradeepNagar"], 1}, {cityIndex["Vara"], 1}, {cityIndex["Dharampuri"], 2} };
    adj[cityIndex["Vara"]] = { {cityIndex["Bhargav"], 1}, {cityIndex["Dharampuri"], 1}, {cityIndex["PradeepNagar"], 2} };
    adj[cityIndex["Dharampuri"]] = { {cityIndex["Bhargav"], 1}, {cityIndex["PradeepNagar"], 2}, {cityIndex["Vara"], 1}, {cityIndex["More"], 1} };
    adj[cityIndex["More"]] = { {cityIndex["Dharampuri"], 2} };
    adj[cityIndex["PradeepNagar"]] = { {cityIndex["Vizianagaram"], 3}, {cityIndex["Bhargav"], 1}, {cityIndex["Vara"], 2}, {cityIndex["Dharampuri"], 2}, {cityIndex["Dmart"], 2}, {cityIndex["Bhavish"], 10} };
    adj[cityIndex["Dmart"]] = { {cityIndex["PradeepNagar"], 2} };
    adj[cityIndex["Bhavish"]] = { {cityIndex["NCS"], 1}, {cityIndex["PradeepNagar"], 10} };
    adj[cityIndex["NCS"]] = { {cityIndex["Bhavish"], 1}, {cityIndex["Railway"], 1} };
    adj[cityIndex["Railway"]] = { {cityIndex["BusStand"], 1}, {cityIndex["NCS"], 1} };
    adj[cityIndex["BusStand"]] = { {cityIndex["SVN"], 1}, {cityIndex["Railway"], 1} };
    adj[cityIndex["SVN"]] = { {cityIndex["Mandi"], 1}, {cityIndex["BusStand"], 1} };
    adj[cityIndex["Mandi"]] = { {cityIndex["Smart"], 1}, {cityIndex["Bhashyam"], 1} };

    string sourceCity, destinationCity;
    cout << "Enter source city: ";
    getline(cin, sourceCity);
    cout << "Enter destination city: ";
    getline(cin, destinationCity);

    if (cityIndex.find(sourceCity) == cityIndex.end() || cityIndex.find(destinationCity) == cityIndex.end()) {
        cout << "Invalid city name(s) provided." << endl;
        return 1;
    }

    int source = cityIndex[sourceCity];
    int destination = cityIndex[destinationCity];

    dijkstra(adj, cityNames, source, destination);

    return 0;
}
