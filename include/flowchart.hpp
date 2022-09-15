#ifndef FLOWCHART_HPP
#define FLOWCHART_HPP

#include <map>
#include <set>

template<typename Data, typename Choice>
struct FlowchartNode {
  using ChoiceMap = std::map<Choice, const FlowchartNode<Data, Choice> *>;

  FlowchartNode() {
    // empty
  }

  FlowchartNode(Data data, ChoiceMap choice_map) :
    data(data), choice_map(choice_map) {
    // all work done in init list
  }

  void operator =(FlowchartNode<Data, Choice> &&other) {
    this->data = other.data;
    this->choice_map = other.choice_map;
  }

  Data data;
  ChoiceMap choice_map;

  const FlowchartNode<Data, Choice> *choice(const Choice c) const;
  const std::set<Choice> choices() const;
};

template<typename Data, typename Choice>
const FlowchartNode<Data, Choice> *FlowchartNode<Data, Choice>::choice(Choice c) const {
  return choice_map.at(c);
}

template<typename Data, typename Choice>
const std::set<Choice> FlowchartNode<Data, Choice>::choices() const {
  std::set<Choice> c;

  for (const auto &[k, v] : choice_map) {
    (void) v;  // v is unused
    c.insert(k);
  }

  return c;
}

#endif
