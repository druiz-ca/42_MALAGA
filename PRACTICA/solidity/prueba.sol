// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract Ejemplodecontrato
{
    uint private counter;
    // private: solo podemos comprobarlo mediante funciones

    function incrementCounter() public {
        counter++;
    }

    function getCounter() public view returns (uint)
    {
        return counter;
    }

    function deposit() public payable {}
}