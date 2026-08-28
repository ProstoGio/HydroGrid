# HydroGrid — Presentation

Everything visual and interactive: the molecular loop simulation, the live energy
dashboard, the full system schematic, and the slide decks.

## Contents

| Folder / File | What it is |
|---|---|
| [`simulation/`](https://prostogio.github.io/HydroGrid/presentation/simulation) | Molecular closed-loop visual — solar splitting water into H₂/O₂ and recombining it each season |
| [`dashboard/`](https://prostogio.github.io/HydroGrid/presentation/dashboard/) | Interactive energy simulation — real winter data, adjustable panel/tank size, Hydrogen vs. Li-Ion vs. LiFePO4 comparison |
| [`schematics/`](https://prostogio.github.io/HydroGrid/presentation/schematics/) | Full component-level system diagram, hover for details — English, Russian, and Georgian in one page via the language toggle |
| `slides/HydroGrid_Presentation.pdf` | Slide deck, English |
| `slides/HydroGrid_Presentation_KA.pdf` | Slide deck, Georgian |

## Viewing

- **On GitHub:** click either PDF in `slides/` — it renders inline, page by page, no download needed.
- **Live pages:** the three interactive links above are served directly via GitHub Pages, no setup required.

## Notes

- The dashboard and schematic both reimplement the project's underlying formulas/data
  in JavaScript so they run directly in a browser — the original C++ implementation
  lives in [`../src/`](../src/).
- The schematic is a single file with a language toggle (EN / RU / ქარ), not separate
  pages per language.
