#include <cstdio>
#include <string>
#include <vector>

#include "flowchart.hpp"

using FCN = FlowchartNode<std::string, std::string>;

int main() {
  const FCN &get_flowchart(void);  // void specified to disambiguate against object initialization
  int get_int(const char *prompt);

  auto *node = &get_flowchart();

  while (true) {
    std::printf("\n\n%s\n", node->data.c_str());

    auto choices_set = node->choices();
    if (choices_set.size() == 0) break;

    std::vector<std::string> choices_vec(choices_set.begin(), choices_set.end());
    using ChoiceCount = std::vector<std::string>::size_type;

    for (ChoiceCount i = 0; i < choices_vec.size(); ++i) {
      std::printf("%-5d | %s\n", i, choices_vec.at(i).c_str());
    }

    ChoiceCount choice = get_int("> ");

    node = &node->choice(choices_vec.at(choice));
  }

  std::printf("Done!\n");
}

int get_int(const char *prompt) {
  int out = 0;

  while (true) {
    std::printf("%s", prompt);

    char buf[16];

    if (std::fgets(buf, 16, stdin) != nullptr && std::sscanf(buf, "%d", &out) == 0) {
      std::printf("Please enter a valid integer.\n");
      continue;
    }

    break;
  }

  return out;
}

const FCN &get_flowchart() {
  static const FCN res_p308 {"Page 308",     {}};
  static const FCN res_full {"Fulfillment!", {}};
  static const FCN res_p258 {"Page 258",     {}};
  static const FCN res_p300 {"Page 300",     {}};
  static const FCN res_p277 {"Page 277",     {}};
  static const FCN res_p255 {"Page 255",     {}};
  static const FCN res_p43  {"Page 43",      {}};
  static const FCN res_p1   {"Page 1",       {}};
  static const FCN res_p197 {"Page 197",     {}};
  static const FCN res_p96  {"Page 96",      {}};
  static const FCN res_p195 {"Page 195",     {}};
  static const FCN res_p284 {"Page 284",     {}};
  static const FCN res_p299 {"Page 299",     {}};
  static const FCN res_p303 {"Page 303",     {}};
  static const FCN res_p128 {"Page 128",     {}};
  static const FCN res_p171 {"Page 171",     {}};
  static const FCN res_p6   {"Page 6",       {}};
  static const FCN res_p18  {"Page 18",      {}};
  static const FCN res_p70  {"Page 70",      {}};
  static const FCN res_p154 {"Page 154",     {}};
  static const FCN res_p176 {"Page 176",     {}};
  static const FCN res_p78  {"Page 78",      {}};
  static const FCN res_p180 {"Page 180",     {}};
  static const FCN res_p323 {"Page 323",     {}};
  static const FCN res_p314 {"Page 314",     {}};
  static const FCN res_p319 {"Page 319",     {}};

  static const FCN node_00 {
    "Enough?",
    {
      {
        "Yes",
        res_full,
      },
      {
        "No. You can literally never have too many dogs. "
        "We should not stop until all that exists in the cosmos "
        "has been consumed by a happy, barking mass.",
        res_p308,
      },
    }
  };
  static const FCN node_01 {
    "More dogs",
    {
      {
        "Yes",
        node_00,
      },
    }
  };
  static const FCN node_02 {
    "Enough?",
    {
      {
        "Yes",
        res_full,
      },
      {
        "No. You can never have too many dogs.",
        node_01,
      },
    }
  };
  static const FCN node_03 {
    "Get more dogs",
    {
      {
        "Yes",
        node_02,
      },
    }
  };
  static const FCN node_04 {
    "Are you satisfied?",
    {
      {
        "Yes",
        res_full,
      },
      {
        "No. I think we need more dogs.",
        node_03,
      },
    }
  };
  static const FCN node_05 {
    "Get a dog",
    {
      {
        "Yes",
        node_04,
      },
    }
  };
  static const FCN node_06 {
    "What kinds of things about eggs?",
    {
      {
        "True things",
        res_p300,
      },
      {
        "False things",
        res_p258,
      },
    }
  };
  static const FCN node_07 {
    "What do you really want to do?",
    {
      {
        "I want to shoot a laser at a sorceress",
        res_p43,
      },
      {
        "I want a dog",
        node_05,
      },
      {
        "I want to tell people things about eggs",
        node_06,
      },
    }
  };
  static const FCN node_08 {
    "Reflect on your life",
    {
      {
        "OK",
        node_07,
      },
    }
  };

  return node_08;
}
