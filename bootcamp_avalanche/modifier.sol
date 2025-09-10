// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract myContract
{
    address public owner;
    string public dato;

    constructor()
    {
        owner = msg.sender; 
    }

    // modifier -> 
    modifier onlyOwner()
    {
        require(msg.sender == owner, "solo propietario");
        _;
    }

    // onlyOwner->  indica que antes de ejecutar el contenido de la ft ejecutará el "onlyOwner" 
    // para hacer la comporbación antes, así evita ejecutar innecesariamente el código
    function myRestrictedFunction() public onlyOwner
    {
        dato = "hola";
    }
}
/* EXPLICACIÓN:
- la ft myREstrict... especifica al final que antes de ejecutarse debe comprobar el onlyOwner
por lo que salta ahí, y si el required está OK entonces salta a "_;" que conecta de nuevo con el 
contenido de la ft original myRestricte.....
- */