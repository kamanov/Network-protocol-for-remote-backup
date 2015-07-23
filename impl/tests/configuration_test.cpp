#include <bandit/bandit.h>
#include "client/clientconfiguration.h"

using namespace bandit;

go_bandit([](){
    describe("Client configuration:", [](){
      it("should provide client configuration parameters", [&](){
          ClientConfiguration* cfg = ClientConfiguration::getInstance();
          AssertThat(cfg != nullptr, Equals(true));
          AssertThat(cfg->serverInfo().ip_addr.empty(), Equals(false));
          AssertThat(cfg->serverInfo().port, IsGreaterThan(0));
      });
    });
});

