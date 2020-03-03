# HondaisCoin Core [HNDC]
==========================
## What is HondaisCoin? 
HondaisCoin is a cryptocurrency like litecoin, although it does not use SHA256 as its proof of work (POW). Taking development cues from Tenebrix and Litecoin, HondaisCoin currently employs a simplified variant of scrypt.

 Official Page: https://www.hondaiscoin.com/
 Block Explorer: http://info.hondaiscoin.com
 
 - Coin Name: HondaisCoin
 - Currency unit : HNDC
 - Algorithm : Scrypt
 - Block Interval : 1 minute (60 seconds)
 - Difficulty Retarget : Every block (using Kimoto's Gravity Well)
 - Supply : 50,000,000,000 HNDC
 - Max Total supply: 100,000,000,000 HNDC
 - Premine: First 20 block is 1,500,000,000 HNDC 
 - Bonus reward for block 21 to 10,000 of 5000HNDC
 - Bonus reward for block 10,000 - 25,000 of 2000HNDC
 - Bonus reward for block 25,000 - 100,000 of 1000HNDC
 - Bonus reward for block 100,000 - 1,200,000 of 500 HNDC
 - Subsidy is cut in half every 200,000 blocks starting at block 1600000
  
### Overview plz make hondaiscoind/hondaiscoin-cli/hondaiscoin-qt

  The following are developer notes on how to build HondaisCoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

  - [OSX Build Notes](doc/build-osx.md)
  - [Unix Build Notes](doc/build-unix.md)
  - [Windows Build Notes](doc/build-msw.md)

 
# hondaiscoin.conf

  - listen=1
  - rpcallowip=127.0.0.1
  - rpcport=25546
  - port=25547
  - rpcuser=HNDCuser
  - rpcpassword=HNDCpassword
  - addnode=173.212.220.139


**DEBUG_LOCKORDER**

HondaisCoin Core is a multithreaded application, and deadlocks or other multithreading bugs
can be very difficult to track down. Compiling with -DDEBUG_LOCKORDER (configure
CXXFLAGS="-DDEBUG_LOCKORDER -g") inserts run-time checks to keep track of what locks
are held, and adds warning to the debug.log file if inconsistencies are detected.
