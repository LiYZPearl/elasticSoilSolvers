//InitEffSigmazz < DynamicEffsigmazz
//Criteria extended from Okusa(1985)

scalarField& liqueFlagOkusaI = liqueFlagOkusa.internalField();
//scalarField& InitEffSigmazzI = InitEffSigmazz.internalField();
scalarField EffSigmazzI = sigma.component(symmTensor::ZZ);

forAll (liqueFlagOkusaI,cellI)
{
   scalar lq = -(InitEffSigmazzI[cellI]) - EffSigmazzI[cellI];
   if (lq <= 0)
    {
     liqueFlagOkusaI[cellI] = 1;
    }
   else
    {
     liqueFlagOkusaI[cellI] = 0;
    }   
}



