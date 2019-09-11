## Pickup

In RS and FRLG, Pickup just has a static item list to pick from. Emerald expanded the number of items available for Pickup significantly, and, in the process, changed it from a list to a table - each row corresponds to a particular level range.

This ports Emerald's Pickup behavior to Fire Red.

### Build Instructions

See [here](https://gist.github.com/Zeturic/db1611cc7b17c3140f9b9af32e1b596b) for the prequisites and help in installing them.

#### Cloning the repo and building the tools

Open your terminal to whatever folder you want to download this repo into. Then, do the following to download the repo and build the included tools:

```shell
$ git clone https://github.com/Zeturic/bpre-field-pickup.git
$ cd bpre-field-pickup
$ ./build_tools.sh
```

#### Adding your ROM

Copy your ROM to this directory and rename it `rom.gba`.

#### Configuration

##### Pickup item list

It is initially set up to match Emerald's pickup item list.

If you've added custom items to your ROM and intend to make them available via Pickup, you will need to add appropriate `#define`s to `include/constants/items.h`.

If you want to customize the items available through Pickup, modify `sPickupItems` and `sRarePickupItems` in `src/pickup.c`. The best way to understand how the order works is to visualize it with a table like [this](https://bulbapedia.bulbagarden.net/wiki/Pickup_(Ability)#Pok.C3.A9mon_Emerald).

`sPickupItems` traces an L-shape along the common (not 1%) items; basically, start in the top left with Potion, go down to Hyper Potion, and then right to Max Elixir. `sRarePickupItems` does the same for the rare (1%) items; it traces from Hyper Potion down to Leftovers and then right to TM26.

##### Where to insert

The build system is smart enough to find enough free space on its own, but if you want it to be inserted at a particular address, you can specify it by updating the definition of `START_AT` in `config.mk`.

If the given address is acceptable (i.e. is word-aligned and has enough bytes of free space), it will be inserted there. Otherwise, it will just use `START_AT` to determine where in the ROM it should start looking for free space.

#### Building the project itself

Once you're ready, run the following to build the project:

```shell
make
```

This won't actually modify `rom.gba`, instead your output will be in `test.gba`. Naturally, test it in an emulator.

### Credits

The project structure and some of the build tools are from [pokeemerald](https://github.com/pret/pokeemerald).
