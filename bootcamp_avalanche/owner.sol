// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract Owner
{
    string private storedInfo;
        //private-> no accesible desde fuera del contrato
    address public owner;

    constructor()
    {
        owner = msg.sender; 
        // establece como propietario del contrato al que ejecuta el contrato
    }

    // External -> Solo puede ser llamada desde fuera del contrato
        // memory -> var temporal que existe durante la ejeción de la función
    function setInfo(string memory myInfo) external 
    {
        // require-> si la condición no se cumple sale del contrato
            // Permite lanzar un mensaje de error
            // así se evita hacer gasto de gas al no completar la ejecución
        require(msg.sender == owner, "only owner");
        storedInfo = myInfo;
    }

    // View-> la ft no modifica el estado del contrato
    // Avisa que devolverá un string que se almacenará en memory
    function getInfo() external view returns (string memory)
    {
        return storedInfo;
    }
}
/* COMPROBACIÓN:
- si se ejecuta una primera vez con una cuenta (ACOUNT) y luego con otra cuenta
nos dará error al ver que no es el mismo "owner" 
(en la teminal nos saldrá una cruz roja indicando que no ha podido hacer la 
transacción */