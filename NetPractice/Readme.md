*This project has been created as part of the 42 curriculum by [your_login_here].*

# NetPractice

## Description

NetPractice is a 42 School project focused on the fundamentals of computer networking. The goal of the project is to build and reinforce practical knowledge of IP networking by solving a series of increasingly complex network topology puzzles.

Each level presents an incomplete network diagram — made up of hosts, routers, and switches — with missing or incorrect information such as IP addresses, subnet masks, or gateway configurations. The objective is to fill in the missing values so that every device on the network can communicate correctly with every other device it is supposed to reach, while respecting real-world addressing constraints (valid host ranges, network/broadcast addresses, routing consistency, etc.).

The project is entirely done through a graphical training interface provided by the school and does not involve writing or compiling any code. It is designed to build intuition for:

- How IP addresses and subnet masks define a network's boundaries
- How routers use routing tables to forward traffic between networks
- How to size subnets correctly for a given number of hosts
- How topology (cabling, switches, routers) affects reachability

## Instructions

### Running the training interface

1. Clone this repository.
2. Launch the NetPractice interface using the provided script:
   ```bash
   ./run.sh
   ```
3. This will open the graphical training tool where each level's topology can be viewed and edited.

### Solving a level

1. Select the level to work on from the interface.
2. Click on the editable fields (IP address, subnet mask, gateway, etc.) on each host/router and fill in valid values.
3. Use the built-in "Check" / "Verify" function to test whether the configured topology allows full connectivity between all required devices.
4. Iterate until the level is validated (all connections marked as reachable).

### Exporting a configuration

Once a level is successfully validated:

1. Use the interface's export function to save the level's configuration as a file.
2. Rename/move the exported file to the root of this repository, following the naming convention expected by the evaluator (e.g. `level1.txt`, `level2.txt`, etc.).
3. Repeat for every level required by the subject.

### Submission requirements

- **10 exported configuration files (one per level) must be placed at the root of this repository.**
- Each file must correspond to a validated (working) configuration for its respective level.
- Do not modify the exported files by hand after generation — they should reflect the state validated by the training tool.

## Resources

### Networking concepts studied

- TCP/IP addressing (IPv4)
- Subnet masks and CIDR notation
- Network, broadcast, and usable host address calculation
- Default gateways
- Static routing and routing tables
- Routers vs. switches (Layer 2 vs. Layer 3 devices)
- The OSI model (particularly the Physical, Data Link, Network, and Transport layers)
- Point-to-point vs. broadcast network segments
- VLSM (Variable Length Subnet Masking) for efficient address allocation

### References

- NetworkChuck videos about subneting
- [subnetting.net](https://subnetting.net) – interactive subnetting practice
- 42 School internal NetPractice subject PDF

### AI usage

AI was used during this project strictly as a learning aid, not to solve levels directly:

- Clarifying theoretical concepts such as subnet mask calculation, CIDR notation, and how routing tables determine the next hop.
- Explaining the difference between routers and switches and their respective roles at different OSI layers.
- Helping debug reasoning on specific puzzle levels by asking guiding questions (e.g. "why would this host be unreachable given this mask?") rather than providing direct answers.
- Assisting with the structure and wording of this README file.

No AI tool was used to generate the exported level configurations themselves; those were solved manually using the concepts above.