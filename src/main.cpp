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
      std::printf("%-5ld | %s\n", i, choices_vec.at(i).c_str());
    }

    ChoiceCount choice = get_int("> ");

    node = node->choice(choices_vec.at(choice));
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
        &res_full,
      },
      {
        "No. You can literally never have too many dogs. "
        "We should not stop until all that exists in the "
        "cosmos has been consumed by a happy, barking mass.",
        &res_p308,
      },
    }
  };
  static const FCN node_01 {
    "More dogs",
    {
      {
        "Yes",
        &node_00,
      },
    }
  };
  static const FCN node_02 {
    "Enough?",
    {
      {
        "Yes",
        &res_full,
      },
      {
        "No. You can never have too many dogs.",
        &node_01,
      },
    }
  };
  static const FCN node_03 {
    "Get more dogs",
    {
      {
        "Yes",
        &node_02,
      },
    }
  };
  static const FCN node_04 {
    "Are you satisfied?",
    {
      {
        "Yes",
        &res_full,
      },
      {
        "No. I think we need more dogs.",
        &node_03,
      },
    }
  };
  static const FCN node_05 {
    "Get a dog",
    {
      {
        "Yes",
        &node_04,
      },
    }
  };
  static const FCN node_06 {
    "What kinds of things about eggs?",
    {
      {
        "True things",
        &res_p300,
      },
      {
        "False things",
        &res_p258,
      },
    }
  };
  static const FCN node_07 {
    "What do you really want to do?",
    {
      {
        "I want to shoot a laser at a sorceress",
        &res_p43,
      },
      {
        "I want a dog",
        &node_05,
      },
      {
        "I want to tell people things about eggs",
        &node_06,
      },
    }
  };
  static const FCN node_08 {
    "Reflect on your life",
    {
      {
        "OK",
        &node_07,
      },
    }
  };
  static const FCN node_09 {
    "Do you think bugs should get paid?",
    {
      {
        "Yes",
        &res_p96,
      },
      {
        "No",
        &node_08,
      },
    }
  };
  static const FCN node_10 {
    "Travel back in time to undo your crimes",
    {
      {
        "OK",
        &res_p277,
      },
    }
  };
  static const FCN node_11 {
    "Do you want to?",
    {
      {
        "Yes",
        &res_p258,
      },
      {
        "No",
        &res_p255,
      },
    }
  };
  static const FCN node_12 {
    "Have you committed any crimes?",
    {
      {
        "Yes",
        &node_10,
      },
      {
        "No",
        &node_11,
      },
      {
        "Not sure",
        &res_p255,
      },
    }
  };
  static const FCN node_13 {
    "What do you want to bring?",
    {
      {
        "My fake identity",
        &node_12,
      },
      {
        "Weird opinions",
        &node_09,
      },
      {
        "Iron vapor",
        &res_p18,
      },
      {
        "Jupiter",
        &res_p70,
      },
    }
  };
  static const FCN node_14 {
    "Do you like your neighbor?",
    {
      {
        "Yes",
        &res_p78,
      },
      {
        "No",
        &node_13,
      },
    }
  };
  static const FCN node_15 {
    "How much soup?",
    {
      {
        "1 bowl",
        &res_p197,
      },
      {
        "10\u2074\u2070 bowls",  // 10^40 bowls
        &res_p1,
      },
    }
  };
  static const FCN node_16 {
    "What food do you order?",
    {
      {
        "A cloud",
        &res_p195,
      },
      {
        "Ammonia",
        &res_p284,
      },
      {
        "Soup",
        &node_15,
      },
      {
        "Breadsticks",
        &res_p299,
      },
      {
        "The sun",
        &res_p303,
      },
    }
  };
  static const FCN node_17 {
    "Okay, there's the diner!",
    {
      {
        "Keep driving forever",
        &res_p128,
      },
      {
        "Stop",
        &node_16,
      },
    }
  };
  static const FCN node_18 {
    "Are you flying near any strong magnets?",
    {
      {
        "Yes",
        &res_p171,
      },
      {
        "No",
        &node_17,
      },
    }
  };
  static const FCN node_19 {
    "Where do you sit in the helicopter?",
    {
      {
        "Inside",
        &node_18,
      },
      {
        "On the rotor",
        &res_p6,
      },
    }
  };
  static FCN node_20;
  static const FCN node_21 {
    "Does this road lead to Rome?",
    {
      {
        "Yes",
        &node_20,
      },
      {
        "No",
        &node_17,
      },
      {
        "No, but it should",
        &res_p154,
      },
    }
  };
  node_20 = (FCN) {
    "Pick a different road",
    {
      {
        "OK",
        &node_21,
      },
    }
  };
  static const FCN node_22 {
    "How do you want to drive?",
    {
      {
        "Fast",
        &res_p180,
      },
      {
        "Normal",
        &node_21,
      },
      {
        "With a bird",
        &res_p176,
      },
    }
  };
  static const FCN res_p83 {
    "Page 83",
    {
      {
        "Also...",
        &node_18,
      },
    }
  };
  static const FCN node_23 {
    "How do you get there?",
    {
      {
        "Car",
        &node_22,
      },
      {
        "Helicopter",
        &node_19,
      },
      {
        "Plane",
        &res_p83,
      },
    }
  };
  static const FCN node_24 {
    "How do you want to visit?",
    {
      {
        "I want to land a probe on the surface",
        &res_p323,
      },
      {
        "Briefly, via teleporter",
        &res_p314,
      },
    }
  };
  static const FCN node_25 {
    "Are you wearing sunscreen?",
    {
      {
        "Yes",
        &res_p319,
      },
      {
        "No",
        &node_24,
      },
    }
  };
  static const FCN node_26 {
    "Where do you go?",
    {
      {
        "The sun",
        &node_25,
      },
      {
        "A diner",
        &node_23,
      },
    }
  };
  static const FCN node_27 {
    "What do you want to do today?",
    {
      {
        "Brunch",
        &node_26,
      },
      {
        "Go to neighborhood party",
        &node_14,
      },
      {
        "I don't know",
        &node_08,
      },
    }
  };
  static const FCN root {
    "Congratulations, you have acquired a copy of "
    "\x1b[4mWHAT IF? 2\x1b[0m!\n"  // underline
    "(Out today [2022-09-13], xkcd.com/whatif2)",
    {
      {
        "Awesome!",
        &node_27,
      },
    }
  };

  return root;
}
