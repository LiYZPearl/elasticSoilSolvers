    const dictionary& stressControl =
        mesh.solutionDict().subDict("anisotropicBiotFoam");

    int nCorr(readInt(stressControl.lookup("nCorrectors")));
    scalar convergenceTolerance(readScalar(stressControl.lookup("U")));
