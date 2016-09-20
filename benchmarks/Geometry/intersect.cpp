#include "../gen_geometry.hpp"

vector<int> test_isis_ll(vector<pair<Line,Line>> query) {
  vector<int> res;
  for (auto i: query) {
    res.push_back(isis_ll(i.first, i.second));
  }
  return res;
}

vector<int> test_isis_ls(vector<pair<Line,Segment>> query) {
  vector<int> res;
  for (auto i: query) {
    res.push_back(isis_ls(i.first, i.second));
  }
  return res;
}

vector<int> test_isis_lp(vector<pair<Line,Point>> query) {
  vector<int> res;
  for (auto i: query) {
    res.push_back(isis_lp(i.first, i.second));
  }
  return res;
}

vector<int> test_isis_ss(vector<pair<Segment,Segment>> query) {
  vector<int> res;
  for (auto i: query) {
    res.push_back(isis_ss(i.first, i.second));
  }
  return res;
}

vector<int> test_isis_sp(vector<pair<Segment,Point>> query) {
  vector<int> res;
  for (auto i: query) {
    res.push_back(isis_sp(i.first, i.second));
  }
  return res;
}

vector<Point> test_proj(vector<pair<Line,Point>> query) {
  vector<Point> res;
  for (auto i: query) {
    res.push_back(proj(i.first, i.second));
  }
  return res;
}

vector<Point> mirror(vector<pair<Line,Point>> query) {
  vector<Point> res;
  for (auto i: query) {
    res.push_back(mirror(i.first, i.second));
  }
  return res;
}

vector<Point> is_ll(vector<pair<Line,Line>> query) {
  vector<Point> res;
  for (auto i: query) {
    res.push_back(is_ll(i.first, i.second));
  }
  return res;
}
