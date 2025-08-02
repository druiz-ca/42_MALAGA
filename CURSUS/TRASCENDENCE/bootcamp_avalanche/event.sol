// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract MyContract
{
    event MyEvent(address indexed sender, uint256 value);

    function triggerEvent() public 
    {
        emit MyEvent(msg.sender, 100);
    }
}