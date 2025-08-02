// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract FirstArray
{
    string[] private storedInfo;

    function addInfo(string memory myInfo) external returns (uint index)
    {
        storedInfo.push();(myInfo);
        index = storedInfo.length - 1;
    }

    function updateInfo(uint index, string memory newInfo) external
    {
        require(index < storedInfo.length, "invalid index");
        storedInfo[index] = newInfo;
    }

    function getOneInfo(uint index) external view returns (string memory)
    {
        require(index < storedInfo.length, "invalid index");
        return storedInfo[index];
    }

    function listAllInfo() external view returns (string[] memory)
    {
        return storedInfo;
    }
}