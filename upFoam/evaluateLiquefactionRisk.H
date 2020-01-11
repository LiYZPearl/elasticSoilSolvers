//scalar z_lm = 0.0; 

const scalarField& pI = p.internalField();
scalarField& liqueFlagI = liqueFlag.internalField();

/*label patchID = mesh.boundaryMesh().findPatchID("seabed");
const scalarField& pPatch = p.boundaryField()[patchID];
const vectorField& bc = mesh.C().boundaryField()[patchID];*/

forAll (liqueFlagI,cellI)
{
  scalar zpos = - mesh.C()[cellI].z();
 /* scalar xpos = mesh.C()[cellI].x();
  scalar ypos = mesh.C()[cellI].y();
  scalar pb(0.0);
  forAll(pPatch,faceI)
   {
     scalar xfpos = bc[faceI].x();
     scalar yfpos = bc[faceI].y();
     if ((xpos-xfpos)<=SMALL && (ypos-yfpos)<=SMALL){pb=pPatch[faceI];}
   } */
  scalar lq = zpos*13000*2.0/3.0;
 
  if ((79290-pI[cellI])>=lq)
    {
      liqueFlagI[cellI] = 1;
    }
   else
   {
      liqueFlagI[cellI] = 0;
    }
}
/*forAll (liqueFlag.boundaryField(),patchI)
{
   scalarField& liqueFlagPatch = liqueFlag.boundaryField()[patchI];
   const scalarField& pPatch = p.boundaryField()[patchI];
   vectorField bc = mesh.C().boundaryField()[patchI];
forAll (liqueFlagPatch, faceI)
   {
       scalar ypos = -5 - bc[faceI].z();
       scalar lq = -1.0/3*ypos*10000;
    if (pPatch[faceI]<=lq)
   {
      liqueFlagPatch[faceI] = 1;
    }
   else
   {
     liqueFlagPatch[faceI] = 0;
    }
}
}
if (wave == "standingWave")
{
forAll (liqueFlagI,cellI)
{
   scalar pi = mathematicalConstant::pi;

   scalar zpos = 320.0 - mesh.C()[cellI].z();
   scalar xpos = mesh.C()[cellI].x();

   scalar kk = 2.0*pi/L_.value();
   scalar ome = 2.0*pi/T_.value();
   const scalar tt = runTime.value();

   scalar pb_ = pb0.value()*Foam::cos(kk*xpos)*Foam::cos(ome*tt);
   scalar lq = (pI[cellI]-pb_)-(1.0+2.0*K0.value())/3.0*(gamma_s-gamma_w).value()*zpos;

   if (lq>SMALL)
   {
      liqueFlagI[cellI] = 1;
      if (zpos > z_lm){z_lm=zpos;}
    }
   else
   {
      liqueFlagI[cellI] = 0;
    }
}

forAll (liqueFlag.boundaryField(),patchI)
{
   scalarField& liqueFlagPatch = liqueFlag.boundaryField()[patchI];
   const scalarField& pPatch = p.boundaryField()[patchI];
   vectorField bc = mesh.C().boundaryField()[patchI];
   
   forAll (liqueFlagPatch, faceI)
   {
   scalar pi = mathematicalConstant::pi;

   scalar zpos = 320.0 - bc[faceI].z();
   scalar xpos = bc[faceI].x();

   scalar kk = 2.0*pi/L_.value();
   scalar ome = 2.0*pi/T_.value();
   const scalar tt = runTime.value();

   scalar pb_ = pb0.value()*Foam::cos(kk*xpos)*Foam::cos(ome*tt);
   scalar lq = (pPatch[faceI]-pb_)-(1.0+2.0*K0.value())/3.0*(gamma_s-gamma_w).value()*zpos;

   if (lq>SMALL)
   {
      liqueFlagPatch[faceI] = 1;if (zpos > z_lm){z_lm=zpos;}
    }
   else
   {
     liqueFlagPatch[faceI] = 0;
    }
   }
}
}
else if (wave == "progressWave")
{
forAll (liqueFlagI,cellI)
{
   scalar pi = mathematicalConstant::pi;

   scalar zpos = 320.0 - mesh.C()[cellI].z();
   scalar xpos = mesh.C()[cellI].x();

   scalar kk = 2.0*pi/L_.value();
   scalar ome = 2.0*pi/T_.value();
   const scalar tt = runTime.value();

   scalar pb_ = pb0.value()*Foam::cos(kk*xpos-ome*tt);
   scalar lq = (pI[cellI]-pb_)-(1.0+2.0*K0.value())/3.0*(gamma_s-gamma_w).value()*zpos;

   if (lq>SMALL)
   {
      liqueFlagI[cellI] = 1;
      if (zpos > z_lm){z_lm=zpos;}
    }
   else
   {
      liqueFlagI[cellI] = 0;
    }
}

forAll (liqueFlag.boundaryField(),patchI)
{
   scalarField& liqueFlagPatch = liqueFlag.boundaryField()[patchI];
   const scalarField& pPatch = p.boundaryField()[patchI];
   vectorField bc = mesh.C().boundaryField()[patchI];
   
   forAll (liqueFlagPatch, faceI)
   {
   scalar pi = mathematicalConstant::pi;

   scalar zpos = 320.0 - bc[faceI].z();
   scalar xpos = bc[faceI].x();

   scalar kk = 2.0*pi/L_.value();
   scalar ome = 2.0*pi/T_.value();
   const scalar tt = runTime.value();

   scalar pb_ = pb0.value()*Foam::cos(kk*xpos-ome*tt);
   scalar lq = (pPatch[faceI]-pb_)-(1.0+2.0*K0.value())/3.0*(gamma_s-gamma_w).value()*zpos;

   if (lq>SMALL)
   {
      liqueFlagPatch[faceI] = 1;if (zpos > z_lm){z_lm=zpos;}
    }
   else
   {
     liqueFlagPatch[faceI] = 0;
    }
   }
}
}
zlmFile<<runTime.value()<<" "<<z_lm<<endl;*/
