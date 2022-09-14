#ifndef FLOWCHART_HPP
#define FLOWCHART_HPP

#include <map>
#include <set>

template<typename Data, typename Choice>
struct FlowchartNode {
  using ChoiceMap = std::map<Choice, const FlowchartNode<Data, Choice> &>;

  const Data data;
  const ChoiceMap choice_map;

  const FlowchartNode<Data, Choice> &choice(const Choice c) const;
  std::set<Choice> choices() const;
};

template<typename Data, typename Choice>
const FlowchartNode<Data, Choice> &FlowchartNode<Data, Choice>::choice(Choice c) const {
  return choice_map.at(c);
}

template<typename Data, typename Choice>
std::set<Choice> FlowchartNode<Data, Choice>::choices() const {
  std::set<Choice> c;

  for (const auto &[k, v] : choice_map) {
    (void) v;  // v is unused
    c.insert(k);
  }

  return c;
}

#endif
